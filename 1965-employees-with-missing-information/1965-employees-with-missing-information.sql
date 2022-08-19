select t.employee_id as employee_id from
    ( select * from employees left join salaries using(employee_id)
     union
      select * from employees right join salaries using(employee_id)
    ) as t
    where t.name is null or t.salary is null 
    order by employee_id;