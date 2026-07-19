PROGRAM Inserting;

USES crt;

CONST
  n = 5;
VAR
  A: array[0..n - 1] of integer = (1, 2, 4, 5, 0);
  index: integer = 0;
  i: integer = 0;
  value: integer = 0;

PROCEDURE
  Print(VAR A: array of integer);
  VAR
    i: integer;
  BEGIN
    for i := 0 to n - 1 do
      Write(A[i]);
    Writeln;
  END;

PROCEDURE
  Insert(VAR A:array of integer; value, index: integer);
  BEGIN
    i := n ;

    repeat
      BEGIN
        A[i] := A[i - 1];
        dec(i);
      END

    until i <= index;
    A[index] := value;
  END;

BEGIN

  Print(A);
  Insert(A, 3, 3);
  Print(A);

END.
