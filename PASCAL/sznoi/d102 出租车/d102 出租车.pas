var
a,b:real;      //double
begin
  readln(a);
  if (a>=0) and (a<=3) then b:=10
   else if (a<=5) and (a>3) then b:=(1.8*(a-3))+10
    else if (a>=5) then b:=(1.8*2+2.7*(a-5))+10;
writeln(b:0:2);
end.
