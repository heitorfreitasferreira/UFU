f(a).
f(b).
g(a).
g(b).
h(b).
k(X):-f(X),g(X),h(X).
  % [trace]  ?- k(X).
  %    Call: (10) k(_10012) ? creep
  %    Call: (11) f(_10012) ? creep
  %    Exit: (11) f(a) ? creep
  %    Call: (11) g(a) ? creep
  %    Exit: (11) g(a) ? creep
  %    Call: (11) h(a) ? creep
  %    Fail: (11) h(a) ? creep
  %    Redo: (11) f(_10012) ? creep
  %    Exit: (11) f(b) ? creep
  %    Call: (11) g(b) ? creep
  %    Exit: (11) g(b) ? creep
  %    Call: (11) h(b) ? creep
  %    Exit: (11) h(b) ? creep
  %    Exit: (10) k(b) ? creep
  % X = b.

  % [trace]  ?- notrace.
  % true.

  % [debug]  ?- nodebug.
  % true.