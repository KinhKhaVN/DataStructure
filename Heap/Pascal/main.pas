PROGRAM HeapDataStructer;

USES crt;

CONST
  capacity = 10;

VAR
  n: integer = 0;
  A: array[0..capacity - 1] of integer;
  i, k: integer;

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

FUNCTION
  Remove: integer;
  VAR
    i, j: integer;
  BEGIN
    Remove := A[0];
    Swap(A[0], A[n - 1]);
    dec(n);
    i := 0;

    while 2*i + 1 < n do
      BEGIN
        j := 2*i + 1;
        if (2*i + 2 < n) AND (A[2*i + 2] < A[j]) then j := 2*i + 2;

        if A[j] >= A[i] then break;
        Swap(A[i], A[j]);
        i := j;
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

  for i := 0 to n - 1 do
    Writeln(Remove);
END.
