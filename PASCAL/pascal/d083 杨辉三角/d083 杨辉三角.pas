var
a:array[0..10,0..11] of integer; // 第一位为行数 第二位为列数
n,m,i:integer;
begin
a[1,1]:=1;
a[0,0]:=1;
readln(n);
 for i:= 1 to n do a[i,0]:=0;
 for i:= 1 to n do a[i,i+1]:=0;
 for i:= 1 to n do
  for m:= 1 to i+1 do
   begin
    a[i,m]:=a[i-1,m]+a[i-1,m-1];
   end;
for i:= 1 to n do
 begin
 for m:= 1 to i do
  begin
   write(a[i,m]);
   if m<=i then write(' ');
  end;
 writeln;
 end;
end.
