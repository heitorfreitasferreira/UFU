% (a)[a,b,c,d] = [a,[b,c,d]].
  % false.

% (b)[a,b,c,d] = [a|[b,c,d]].
  % true.
  
% (c)[a,b,c,d] = [a,b,[c,d]].
  % false.

% (d)[a,b,c,d] = [a,b|[c,d]].
  % true.

% (e)[a,b,c,d] = [a,b,c,[d]].
  % false.

% (f)[a,b,c,d] = [a,b,c|[d]].
  % true.

% (g)[a,b,c,d] = [a,b,c,d,[]].
  % false.

% (h)[a,b,c,d] = [a,b,c,d|[]].
  % true.

% (i)[] = _.
  % true.

% (j)[] = [_].
  % false.

% (k)[] = [_|[]].
  % false.