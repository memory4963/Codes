var
a,b,c,n,i:integer;
d:array[1..32]of longint;
begin
d[1]:=1;
d[2]:=2;
readln(n);
begin
if n>=3 then
for i:= 3 to n+1 do d[i]:=d[i-1]+d[i-2];
end;
writeln(d[n]);
end.
