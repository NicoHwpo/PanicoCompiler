import sys
from typing import Dict, List, Any, Union

class MemoryStack:
    def __init__(self):
        self.memory_stack: List[Dict[int, Any]] = [{}]
    
    def push_frame(self):
        """Push a new memory frame for a function call."""
        self.memory_stack.append({})
    
    def pop_frame(self):
        """Remove the top memory frame."""
        if len(self.memory_stack) > 1:
            self.memory_stack.pop()
    
    def get_value(self, address: int) -> Any:
        """Retrieve value from the most recent frame containing the address."""
        for frame in reversed(self.memory_stack):
            if address in frame:
                return frame[address]
        return None
    
    def set_value(self, address: int, value: Any):
        """Set value in the most recent frame."""
        self.memory_stack[-1][address] = value

class VirtualMachine:
    def __init__(self, obj_file_path: str):
        # Memory management
        self.memory_stack = MemoryStack()
        self.constants: Dict[int, Any] = {}
        self.functions: Dict[str, Dict[str, Any]] = {}
        
        # Execution context
        self.instruction_pointer = 0
        self.quadruples: List[List[str]] = []
        self.call_stack: List[int] = []
        
        # Parse object file
        self.parse_obj_file(obj_file_path)
    
    def parse_obj_file(self, file_path: str):
        """Parse the object file and populate constants, functions, and quadruples."""
        with open(file_path, 'r') as file:
            section = None
            for line in file:
                line = line.strip()
                if not line or line.startswith('#'):
                    continue
                
                if line == 'CONSTANTS':
                    section = 'constants'
                    continue
                elif line == 'FUNCTIONS':
                    section = 'functions'
                    continue
                elif line == 'QUADRUPLES':
                    section = 'quadruples'
                    continue
                
                if section == 'constants':
                    # Split only on the first space to handle strings with spaces
                    parts = line.split(' ', 1)
                    address = int(parts[0])
                    value = parts[1].strip()
                    
                    # Check if it's a string (enclosed in quotes)
                    if value.startswith('"') and value.endswith('"'):
                        self.constants[address] = value[1:-1]
                    else:
                        # Try to convert to float or int
                        try:
                            self.constants[address] = float(value) if '.' in value else int(value)
                        except ValueError:
                            self.constants[address] = value
                
                elif section == 'functions':
                    name, return_type, start_addr, local_int_start, local_float_start, local_vars, params = line.split()
                    self.functions[name] = {
                        'return_type': return_type,
                        'start_address': int(start_addr),
                        'local_int_start': int(local_int_start),
                        'local_float_start': int(local_float_start),
                        'local_vars': int(local_vars),
                        'params': int(params)
                    }
                
                elif section == 'quadruples':
                    parts = line.split(': ')
                    quad_parts = parts[1].split()
                    self.quadruples.append(quad_parts)
    
    def get_value(self, address: Union[int, str]) -> Any:
        """Retrieve value from constants or memory stack."""
        if address == '-1':
            return None
        
        address = int(address)
        if address in self.constants:
            return self.constants[address]
        
        value = self.memory_stack.get_value(address)
        return value if value is not None else address
    
    def set_value(self, address: int, value: Any):
        """Store a value in memory stack."""
        self.memory_stack.set_value(address, value)
    
    def execute(self):
        """Execute the quadruples."""
        while self.instruction_pointer < len(self.quadruples):
            quad = self.quadruples[self.instruction_pointer]
            op = quad[0]
            
            if op == 'GOTO':
                self.instruction_pointer = int(quad[3]) - 1
            
            elif op == 'GOTOF':
                condition = self.get_value(quad[1])
                if not condition:
                    self.instruction_pointer = int(quad[3]) - 1
            
            elif op == 'PRINT':
                value = self.get_value(quad[3])
                print(value)
            
            elif op == '=':
                value = self.get_value(quad[1])
                self.set_value(int(quad[3]), value)
            
            elif op == '+':
                left = self.get_value(quad[1])
                right = self.get_value(quad[2])
                self.set_value(int(quad[3]), left + right)
            
            elif op == '-':
                left = self.get_value(quad[1])
                right = self.get_value(quad[2])
                self.set_value(int(quad[3]), left - right)
            
            elif op == '*':
                left = self.get_value(quad[1])
                right = self.get_value(quad[2])
                self.set_value(int(quad[3]), left * right)
            
            elif op == '/':
                left = self.get_value(quad[1])
                right = self.get_value(quad[2])
                try:
                    self.set_value(int(quad[3]), left / right)
                except ZeroDivisionError:
                    print(f"Error: Division by zero at quadruple {self.instruction_pointer}")
                    break
            
            elif op == '>':
                left = self.get_value(quad[1])
                right = self.get_value(quad[2])
                self.set_value(int(quad[3]), left > right)
                
            elif op == '<':
                left = self.get_value(quad[1])
                right = self.get_value(quad[2])
                self.set_value(int(quad[3]), left < right)
                
            elif op == '==':
                left = self.get_value(quad[1])
                right = self.get_value(quad[2])
                self.set_value(int(quad[3]), left == right)
                
            elif op == '!=':
                left = self.get_value(quad[1])
                right = self.get_value(quad[2])
                self.set_value(int(quad[3]), left != right)
            
            elif op == 'ERA':
                # Prepare a new memory frame for function call
                self.memory_stack.push_frame()
            
            elif op == 'PARAM':
                # Pass parameters to the new memory frame
                param_value = self.get_value(quad[1])
                self.set_value(int(quad[3]), param_value)
            
            elif op == 'GOSUB':
                # Get function name and its start address
                func_name = quad[1]
                if func_name in self.functions:
                    # Save current instruction pointer to return later
                    self.call_stack.append(self.instruction_pointer)
                    
                    # Set instruction pointer to function's start address
                    self.instruction_pointer = self.functions[func_name]['start_address'] - 1
            
            elif op == 'ENDFUNC':
                # Return to the instruction after function call and remove function's memory frame
                if self.call_stack:
                    self.instruction_pointer = self.call_stack.pop()
                    self.memory_stack.pop_frame()
            
            elif op == 'HALT':
                break
            
            self.instruction_pointer += 1

def main(obj_file_path):
    vm = VirtualMachine(obj_file_path)
    vm.execute()

if __name__ == '__main__':
    if len(sys.argv) > 1:
        main(sys.argv[1])
    else:
        print("Please provide an object file path.")