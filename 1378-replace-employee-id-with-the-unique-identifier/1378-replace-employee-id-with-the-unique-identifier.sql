# Write your MySQL query statement below
select empu.unique_id,em.name
from employees em
left join employeeUNI empu
on empu.id=em.id