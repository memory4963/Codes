var
a,b,c,d:integer;
begin
readln(a);
b:=a div 100;
c:=a div 10 -10*b;
d:=a -100*b-10*c;
writeln(b,' ',c,' ',d);
end.