var
n,i:integer;
b:array[1..10] of integer;
begin
readln(n);
for i:= 1 to n do
 read(b[i]);
for i:= n downto 1 do
 write(b[i],' ');
end.
