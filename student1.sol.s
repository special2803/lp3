//SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Studentdata{
    struct Student{
        string name;
        uint age;
        string class;
    }
    Student[] public students;
    
    event StudentAdded(string name, string class);

    event FallbackCalled(address sender, uint256 amount, string message);

    function addStudent(string memory _name, uint _age, string memory _class ) public{
        Student memory newStudent = Student({
            name: _name,
            age: _age,
            class: _class
        });
        students.push(newStudent);
        emit StudentAdded(_name, _class);
    }

    function getTotalStudent()public view returns(uint){
        return students.length;
    }


    function getStudent(uint index)public view returns(string memory, uint, string memory){
        require(index < students.length, "Invalid index");
        Student memory student = students[index];
        return (student.name, student.age, student.class);
    }

    function getAllStudents() public view returns (string[] memory, uint[] memory, string[] memory) {
    uint length = students.length;
    
    string[] memory names = new string[](length);
    uint[] memory ages = new uint[](length);
    string[] memory classes = new string[](length);
    
    for (uint i = 0; i < length; i++) {
        names[i] = students[i].name;
        ages[i] = students[i].age;
        classes[i] = students[i].class;
    }
    
    return (names, ages, classes);
    }

    fallback() external  payable{
        emit FallbackCalled(msg.sender, msg.value, "thank you for using");
    }
    receive() external payable { 
    }
}