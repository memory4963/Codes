var
w:array[1..100]of integer;
t,n,m,i:integer;
begin
readln(n);
for i:= 1 to n do read(w[i]);
t:=w[1];
for i:= 1 to n do write(w[i],' ');
writeln;
for i:= 1 to n do w[i]:=w[i+1];
w[n]:=t;
for i:= 1 to n do write(w[i],' ');
end.