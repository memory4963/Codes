var
a,b,c:array[1..200]of integer;
i,n,m,j,p,q:integer;
begin
i:=0;
n:=0;
p:=0;
repeat
i:=i+1;
read(a[i]);
n:=n+1;
until eoln;
i:=0;
j:=0;
repeat
i:=i+1;
read(b[i]);
j:=j+1;
until eoln;
i:=0;
repeat
i:=i+1;
until b[i]>a[n];
 begin
  for m:= 1 to n do
   begin
   c[m]:=a[m];
   p:=p+1;
   end;
q:=p+1;
  for m:= i to j do
   begin
   c[q]:=b[m];
   p:=p+1;
   q:=q+1;
   end;
 end;
for i:= 1 to p do write(c[i],' ');
end.
