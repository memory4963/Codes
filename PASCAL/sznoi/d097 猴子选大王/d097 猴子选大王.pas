var
n,m,i,k,p:integer;
a:array[1..1000]of boolean;
begin
assign(input,'hzxdw.in');
assign(output,'hzxdw.out');
reset(input);
rewrite(output);
fillchar(a,sizeof(a),true);
readln(n,m);
p:=n;
repeat
 i:=i+1;
 if (i=n+1) and a[i] then
 begin
 i:=0;
 k:=k+1;
 end
  else if a[i] then k:=k+1;
 if k=m then
 begin
  a[i]:=false;
  p:=p-1;
  k:=0;
  readln;
 end;
until p=1;
for i:= 1 to n do if a[i] then writeln(i);
end.
