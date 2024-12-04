# maze

応用情報技術者試験 令和4年度秋期 午後問3 プログラミング 迷路の探索処理

https://www.ap-siken.com/kakomon/04_aki/pm03.html

<img src = "https://github.com/nk12U/maze/blob/main/maze.png"> 

## Command

```
$ git clone https://github.com/nk12U/maze.git
$ gcc maze.c
$ ./a.out
■■■■■■■
■□□■■G■
■□■□□□■
■□□□■□■
■□■□□□■
■S□□■□■
■■■■■■■

path 1:
(1, 1) (1, 2) (1, 3) (2, 3) (3, 3) (3, 4) (4, 4) (5, 4) (5, 5)
path 2:
(1, 1) (1, 2) (1, 3) (2, 3) (3, 3) (3, 2) (4, 2) (5, 2) (5, 3) (5, 4) (5, 5)
path 3:
(1, 1) (2, 1) (3, 1) (3, 2) (3, 3) (3, 4) (4, 4) (5, 4) (5, 5)
path 4:
(1, 1) (2, 1) (3, 1) (3, 2) (4, 2) (5, 2) (5, 3) (5, 4) (5, 5)
```
