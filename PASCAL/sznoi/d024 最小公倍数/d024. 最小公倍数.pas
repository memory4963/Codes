var
a,b,i:integer;
begin
readln(a,b);
for i:= 1 to a*b do
 if (i mod b=0) and (i mod a=0)then
 begin
  writeln(i);
  break;
  end;
end.