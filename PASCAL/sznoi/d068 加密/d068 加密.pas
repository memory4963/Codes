var
a,b,c,d,n,m,i,k,p:integer;
w:char;
begin
repeat
read(w);
 begin
  if (ord(w)<=117)and(ord(w)>=97) then
   begin
    write(chr(ord(w)+5));
   end
    else if (ord(w)<=122)and(ord(w)>117) then
     begin
      write(chr(ord(w)-21));
     end
     else write(w);
 end;
until eoln;
end.