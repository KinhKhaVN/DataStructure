PROGRAM NaiveHashTable;

TYPE
  mang = array of integer;

CONST 
  capa = 5;

VAR
  A: array of integer;

PROCEDURE
  Init(VAR A: mang);
  VAR
    i: integer;
  BEGIN
    SetLength(A, capa);
    for i := 0 to length(A) - 1 do
      A[i] := -1; 
  END;

FUNCTION
  H(CONST x, n: integer): integer;
  BEGIN
    exit(x mod n);
  END;

PROCEDURE
  Print(CONST A: mang);
  VAR
    i: integer;
  BEGIN
    for i := 0 to length(A) - 1 do
      Write(A[i]:2);
    Writeln;
  END;

PROCEDURE
  Put(VAR A: mang; CONST k, v: integer);
  BEGIN
    A[H(k, length(A))] := v;
  END;

FUNCTION
  Get(CONST A: mang; CONST k: integer):integer;
  BEGIN
    exit(A[H(k, length(A))]);
  END;

BEGIN

  Init(A);

  Put(A, 32, 5);
  Put(A, 33, 5);
  Put(A, 34+1, 5);

  Print(A);

END.
