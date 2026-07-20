PROGRAM SingleLinkedListArray;

USES crt;

CONST
  capacity = 5;

VAR
  size: integer = 0;
  A: array[0 .. capacity - 1] of integer;

PROCEDURE
  Push(val: integer);
  BEGIN
    if size >= capacity then
      BEGIN
        Writeln('Can not push ', val, ', Stack is full!');
        Writeln('Top is: ', A[size]);
        Writeln;
        exit;
      END;

    inc(size);
    A[size] := val;
  END;

PROCEDURE
  Pop;
  BEGIN
    if size <= 0 then
      BEGIN
        if size = 0 then
          Writeln('Stack empty!');
        if size < 0 then
          Writeln('Init fail!');
        
        Writeln('Top is: ', A[size]);
        Writeln;
        exit;
      END;
    A[size] := -1;
    dec(size);
  END;

PROCEDURE
  Print;
  VAR
    i: integer;
  BEGIN
    for i := size downto 1 do
      Writeln(A[i]);
  END;

BEGIN
  CLRSCR;

  Push(1);
  Push(2);
  Push(3);
  Push(4);
  Push(5);
  Push(6);
  Push(7);
  Push(8);
  Push(9);
  Push(10);

  Print;
END.
