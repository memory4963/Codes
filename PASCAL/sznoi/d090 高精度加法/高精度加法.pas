var
s1,s2:string;
la,lb:integer;
a,b,c:array[1..500]of integer;
m,i,x:integer;
begin
readln(s1);
la:=length(s1);
for i:= 1 to la do a[i]:=ord(s1[i])-48;
readln(s2);
lb:=length(s2);
for i:= 1 to lb do b[i]:=ord(s2[i])-48;
i:=0;
while (i<=la) or (i<=lb) do
begin
  i:=i+1;
  c[i]:=(x+a[i]+b[i]) mod 10;
  x:=(a[i]+b[i]+x) div 10;
end;
if x<10 then i:=i-1;
for m:= i downto 1 do write(c[m]);
end.
