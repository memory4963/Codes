var
n,m,i,temp,k,x:integer;
a:array[1..1000]of integer;
begin
assign(input,'random.in');
assign(output,'random.out');
reset(input);
rewrite(output);
readln(n);
for i:= 1 to n do read(a[i]);
begin //冒泡排序
  for i:= n-1 downto 1 do
   for m:= 1 to i do
     if a[m]>=a[m+1] then
      begin //change
        temp:=a[m+1];
        a[m+1]:=a[m];
        a[m]:=temp;
      end;
end;
x:=n;
for i:= n-1 downto 1 do
for m:= 1 to i do
if a[i]=a[i+1] then begin
 for k:= i+1 to x do a[k]:=a[k+1];
 x:=x-1;
end;
writeln(x);
for i:= 1 to x do write(a[i],' ');
close(input);
close(output);
end.
