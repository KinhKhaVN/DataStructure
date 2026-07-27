PROGRAM HeapDataStructer;

USES crt;

CONST
  capacity = 10;

VAR
  n: integer = 0;
  A: array[0..capacity - 1] of integer;

PROCEDURE
  Swap(VAR a, b: integer);
  VAR
    tmp: integer;
  BEGIN
    tmp := a;
    a := b;
    b := tmp;
  END;

PROCEDURE
  Print;
  VAR
    i: integer;
  BEGIN
    for i := 0 to n - 1 do
      Write(A[i], ' ');
    Writeln;
  END;

PROCEDURE
  Insert(x: integer);
  VAR
    i: integer;
  BEGIN
    A[n] := x;
    inc(n);

    i := n - 1;

    while (i > 0) AND (A[i] <= A[(i - 1) div 2]) do
      BEGIN
        Swap(A[i], A[(i - 1) div 2]);
        i := (i - 1) div 2;
      END;
  END;

BEGIN
  CLRSCR;

  Insert(10);
  Insert(-2);
  Insert(1);
  Insert(2);
  Insert(3);
  Insert(0);
  Insert(0);
  Print;

END.
