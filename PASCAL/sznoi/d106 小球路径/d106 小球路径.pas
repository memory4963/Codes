var
a,b,c,d:real;
begin
readln(a);
b:=1;
while b>=0.001 do
begin
c:=c+b*a*2;
b:=0.7*b;
end;
writeln(c-a:0:2);
end.
