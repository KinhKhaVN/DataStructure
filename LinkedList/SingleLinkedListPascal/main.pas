PROGRAM LinkList;

USES crt;

TYPE
  pNode = ^Node;
  Node = record
    value: integer;
    next: pNode;
  END;

VAR
  l1, l2: pNode;
  i: integer;
  n: integer = 10;

PROCEDURE
  Init(VAR head: pNode);
  BEGIN
    new(head);
    head := nil;
  END;

PROCEDURE
  Print(head: pNode);
  VAR
    tmpNode: pNode;
  BEGIN
    tmpNode := head;
    if tmpNode = nil then 
      BEGIN
        Writeln('List is empty! Can not print');
        exit;
      END;
    new(tmpNode);

    repeat
      Write(tmpNode^.value, ' ');
      tmpNode := tmpNode^.next;
    until tmpNode = nil;
    Writeln;
  END;

PROCEDURE
  Add(VAR head:pNode; val: integer);
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

PROCEDURE
  InsertAfter(VAR head:pNode; target, val: integer);
  VAR
    tmpNode: pNode;
    newNode: pNode;
  BEGIN
    tmpNode := head;

    while (tmpNode <> nil) AND 
          (tmpNode^.value <> target)
           do 
          tmpNode := tmpNode^.next;

    if tmpNode = nil then
      BEGIN
        Add(head, val);
        exit;
      END;

    new(newNode);
    newNode^.value := val;
    newNode^.next := tmpNode^.next;
    tmpNode^.next := newNode;
    
  END;

PROCEDURE
  Merge(VAR dest, src: pNode);
  VAR
    tmpNode: pNode;
  BEGIN
    if (dest = nil) AND (src = nil) then
      BEGIN
        Writeln('Both list are empty!');
        exit;
      END;
    if dest = nil then 
      BEGIN
        Writeln('Destination is empty!');
        exit;
      END;

    if src = nil then 
      BEGIN
        Writeln('Source is empty!');
        exit;
      END;

    tmpNode := dest;

    while tmpNode^.next <> nil do tmpNode := tmpNode^.next;

    tmpNode^.next := src;

  END;

BEGIN
  CLRSCR;


  Init(l1);
  Init(l2);


  Merge(l1, l2);
  Print(l1);

END.
