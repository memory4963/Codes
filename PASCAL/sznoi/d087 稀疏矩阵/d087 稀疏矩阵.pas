var
k,n,m,i,p,w:integer;
temp:array[1..3,1..100]of integer;
begin
readln(m,n);
for i:=1 to m do
 begin
 for p:= 1 to n do
  begin
   read(k);
   if k<>0 then begin
    w:=w+1;
    temp[w,1]:=i;
    temp[w,2]:=p;
    temp[w,3]:=k;
   end;
  end;
 readln;
 end;
 writeln(w);
for i:= 1 to w do
 writeln(temp[i,1],' ',temp[i,2],' ',temp[i,3]);
end.
