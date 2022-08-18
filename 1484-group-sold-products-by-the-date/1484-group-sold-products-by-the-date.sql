# Write your MySQL query statement below
/*The GROUP BY statement groups rows that have the same values into summary rows.
The GROUP BY statement is often used with aggregate functions (COUNT(), MAX(), MIN(), SUM(), AVG()) to group the result-set by one or more columns.
Another group method we use is GROUP_CONCAT, which concat items of grouped rows and joins them by using "," seperator.
*/
select sell_date, 
    count(distinct(product)) as "num_sold", 
    group_concat(distinct product order by product asc) as "products" 
from activities group by sell_date order by sell_date;
