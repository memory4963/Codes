var
a,b,c,d,e,i:integer;
begin
read(a,b,c);
if a<b then
 begin
  d:=a;
  a:=b;
  b:=d;
 end;
if a<c then
 begin
  d:=a;
  a:=c;
  c:=d;
 end;
if b<c then
 begin
  d:=b;
  b:=c;
  c:=d;
 end;
writeln(a,' ',b,' ',c);
end.

