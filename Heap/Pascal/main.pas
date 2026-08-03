PROGRAM HeapDataStructer;

USES crt;

CONST
  capacity = 10;

TYPE
  Heap = record
    A: array[0..capacity - 1] of integer;
    size: integer;
  END;
VAR
  n: integer = 0;
  A: array[0..capacity - 1] of integer;
  i, k: integer;
  h1, h2: Heap;

PROCEDURE
  Init(VAR h: Heap);
  BEGIN
    h.size := 0;
  END;

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
  Print(VAR h: Heap);
  VAR
    i: integer;
  BEGIN
    for i := 0 to h.size - 1 do
      Write(h.A[i], ' ');
    Writeln;
  END;

PROCEDURE
  Insert(VAR h: Heap; x: integer);
  VAR
    i: integer;
  BEGIN
    h.A[h.size] := x;
    inc(h.size);

    i := h.size - 1;

    while (i > 0) AND (h.A[i] <= h.A[(i - 1) div 2]) do
      BEGIN
        Swap(h.A[i], h.A[(i - 1) div 2]);
        i := (i - 1) div 2;
      END;
  END;

FUNCTION
  Remove(VAR h: Heap): integer;
  VAR
    i, j: integer;
  BEGIN
    Remove := h.A[0];
    Swap(h.A[0], h.A[h.size - 1]);
    dec(h.size);
    i := 0;

    while 2*i + 1 < h.size do
      BEGIN
        j := 2*i + 1;
        if (2*i + 2 < h.size) AND (h.A[2*i + 2] < h.A[j]) then j := 2*i + 2;

        if h.A[j] >= h.A[i] then break;
        Swap(h.A[i], h.A[j]);
        i := j;
      END;

  END;

PROCEDURE
  Merge(VAR dest, src: Heap);
  VAR
    i: integer;
  BEGIN
    for i := 0 to src.size - 1 do
      Insert(dest, src.A[i]);
  END;

BEGIN
  CLRSCR;

  Init(h1);
  Init(h2);
  
  Insert(h1, 10);
  Insert(h1, -2);
  Insert(h1, 1);

  Insert(h2, 2);
  Insert(h2, 3);
  Insert(h2, 0);
  Insert(h2, 0);

  Write('h1: ');
  Print(h1);

  Write('h2: ');
  Print(h2);

  Write('Merge: ');
  Merge(h1, h2);
  Print(h1);

  for i := 0 to h1.size - 1 do
    Writeln(Remove(h1));

END.
