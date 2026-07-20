PROGRAM Inserting;

USES crt;

CONST
  capacity = 10;
VAR
  n: integer = 5;
  A: array[0..capacity - 1] of integer = (1, 2, 4, 5, 0, 0, 0, 0, 0, 0);
  index: integer = 0;
  i: integer = 0;
  value: integer = 0;

PROCEDURE
  Print(VAR A: array of integer);
  VAR
    i: integer;
  BEGIN
    for i := 0 to capacity - 1 do
      Write(A[i], ' ');
    Writeln;
  END;

PROCEDURE
  Insert(VAR A:array of integer; value, index: integer);
  BEGIN
    i := n - 1;

    repeat
      BEGIN
        A[i] := A[i - 1];
        dec(i);
      END

    until i <= index;
    A[index] := value;
    inc(n);
  END;

PROCEDURE
  Remove(VAR A: array of integer; index: integer);
  VAR
    i: integer;
  BEGIN

    for i := index to n do
      A[i] := A[i + 1];

    A[n - 1] := 0;
    dec(n);
  END;

BEGIN

  Print(A);
  Insert(A, 3, 2);
  Insert(A, 10, 2);
  Print(A);
  Remove(A, 2);
  Print(A);

END.
