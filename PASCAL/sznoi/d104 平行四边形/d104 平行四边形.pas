var
k,p,n,m,i:integer;
begin
readln(n);
m:=n-1;
for i:= 1 to n do
 begin
  if m>0 then begin
  for k:= 1 to m do write(' ');
  m:=m-1;
  end;
 for p:= 1 to n do write('*');
 writeln;
 end;
end.
