var
a,b,c,i,x,y:longint;
function fac(a:integer):integer;
var
i:integer;
begin
fac:=1;
for i:=1 to a do
 fac:=fac*i;
end;
begin
  for i:= 1 to 3 do
  begin
  read(x);
  if x=0 then y:=y+1;
  if x>0 then y:=y+fac(x);
  end;
  writeln(y);
end.

