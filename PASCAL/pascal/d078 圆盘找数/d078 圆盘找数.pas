var
a:array[1..23]of integer;
b,c,d,e,f,g,n,m,i,k,p:integer;
begin
 d:=0;
 e:=0;
 for b:=1 to 20 do read(a[b]);
 for b:=21 to 23 do a[b]:=a[b-20];
 for c:= 1 to 20 do
  if (a[c]+a[c+1]+a[c+2]+a[c+3])>d then begin
     d:=(a[c]+a[c+1]+a[c+2]+a[c+3]);
     e:=c;
     end;
write(e,' ',d);
end.
