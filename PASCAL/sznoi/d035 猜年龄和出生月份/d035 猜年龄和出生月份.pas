var
a,b,c:integer;
begin
readln(c);
for a:=  0 to 110 do
 for b:= 1 to 12 do
  if ((2*b+5)*50+a-365)=c then
   writeln(a,' ',b);
end.
