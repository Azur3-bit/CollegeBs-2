sql -- collage bs 

CREATE TABLE students 
(
    emp_id	int(512),
    e_name	VARCHAR(512),
    dept	VARCHAR(512),
    salary	VARCHAR(512),
    age	VARCHAR(512)
);

INSERT INTO students (emp_id, e_name, dept, salary, age) VALUES (101, 'rahul', 'cse ', '0', '21');
INSERT INTO students (emp_id, e_name, dept, salary, age) VALUES (102, 'sunil', 'cse ', '0', '21');
INSERT INTO students (emp_id, e_name, dept, salary, age) VALUES (103, 'kunwar', 'cse', '0', '21');

select AVG(emp_id)
from students;

select SUM(emp_id)
from students;


select MIN(emp_id)
from students;

select MAX(emp_id)
from students;


select COUNT(emp_id)
from students;

