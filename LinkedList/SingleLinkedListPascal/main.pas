PROGRAM LinkList;

USES crt;

TYPE
  pNode = ^Node;
  Node = record
    value: integer;
    next: pNode;
  END;

VAR
  head: pNode;
  i: integer;
  n: integer = 10;

PROCEDURE
  Init;
  BEGIN
    head := nil;
  END;

PROCEDURE
  Print;
  VAR
    tmpNode: pNode;
  BEGIN
    new(tmpNode);
    tmpNode := head;

    repeat
      Write(tmpNode^.value, ' ');
      tmpNode := tmpNode^.next;
    until tmpNode = nil;

  END;

PROCEDURE
  Add(val: integer);
  VAR
    newNode: pNode;
    tmpNode: pNode;
  BEGIN
    new(newNode);
    newNode^.value := val;
    newNode^.next := nil;

    if head = nil then
      BEGIN
        head := newNode;
        exit;
      END;

    tmpNode := head;

    while tmpNode^.next <> nil do
      tmpNode := tmpNode^.next;

    tmpNode^.next := newNode;

  END;

BEGIN
  CLRSCR;


  Init;
  for i := 1 to n do
    Add(i);
  Print;

END.
