% ?- X = 3*4.
% X = 3*4.

% ?- X is 3*4.
% X = 12.

% ?- 4 is X.
% ERROR: Arguments are not sufficiently instantiated
% ERROR: In:
% ERROR:   [10] 4 is _17874
% ERROR:    [9] <user>

% ?- X = Y.
% X = Y.

% ?- 3 is 1+2.
% true.

% ?- 3 is +(1,2).
% true.

% ?- 3 is X+2.
% ERROR: Arguments are not sufficiently instantiated
% ERROR: In:
% ERROR:   [10] 3 is _3836+2
% ERROR:    [9] <user>

% ?- X is 1+2.
% X = 3.

% ?- 1+2 is 1+2.
% false.

% ?- is(X,+(1,2)).
% X = 3.

% ?- 3+2 = +(3,2).
% true.

% ?- *(7,5) = 7*5.
% true.

% ?- *(7,+(3,2)) = 7*(3+2).
% true.

% ?- *(7,(3+2)) = 7*(+(3,2)).
% true.