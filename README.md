# Phoilosophers

## ✅説明

C言語にて「食事する哲学者」の問題を解きます💪<br>
マルチスレッドプログラミングの問題です。<br>

## ✅環境とファイル階層

```
> uname -a
Linux ubuntuv 5.13.0-51-generic #58~20.04.1-Ubuntu
SMP Tue Jun 14 11:29:12 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux
> gcc --version
gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

```
./philo
|--includes
|  |--philo.h
|
|--Makefile
|--README.md
|--header_usage.c
|--init.c
|--launcher.c
|--main.c
|--print.c
|--utils.c
```

## ✅引数の説明

```
./philo [number_of_philosophers] [time_to_die] [time_to_eat time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

> 注意
引数に数字が来た場合にはゼロとして処理します。

### number_of_philosophers
哲学者の数。<br>
これはフォークの数と等しくなる。<br>
条件：`2 <= number_of_philosophers <= 200`

### time_to_die（ミリ秒単位）
哲学者が死ぬまでの時間。<br>
哲学者が最後の食事の開始またはシミュレーションの開始から`time_to_die`ミリ秒を食べ始めなかった場合、彼らは死にます☠️<br>
条件：`60 <= time_to_die`

### time_to_eat（ミリ秒単位）
哲学者が食べるのにかかる時間。<br>
その間、彼らは2つのフォークを保持する必要があります。<br>
条件：`60 <= time_to_eat`

### time_to_sleep（ミリ秒単位）
哲学者が眠るのに費やす時間。<br>
条件：`60 <= time_to_eat`

### number_of_times_each_philosopher_must_eat（オプションの引数）
すべての哲学者が少なくとも`number_of_times_each_philosopher_must_eat`回食べた場合、シミュレーションは停止します。<br>
指定しない場合、哲学者が死亡するとシミュレーションが停止します。<br>
条件：`0 < number_of_times_each_philosopher_must_eat`

## ✅代表的な引数のケースと出力

```shell
>  ./philo 3 410 200 200
```

`3`人の哲学者が食事間隔`410`ms以内、食事時間`200`ms、睡眠時間`200`msで生活します。

```
0	1 has taken a fork  // 哲学者1が右フォークを取った
1	1 has taken a fork  // 哲学者1が左フォークを取った
2	1 is eating         // 哲学者1がご飯を食べている
2	3 has taken a fork  // 哲学者3が右フォークを取った
202	1 is sleeping       // 哲学者1が眠っている...zzz
202	2 has taken a fork  // 哲学者2が右フォークを取った
202	3 has taken a fork  // 哲学者3が左フォークを取った
202	3 is eating         // 哲学者3がご飯を食べている
402	1 is thinking       // 哲学者1が考えている
402	1 has taken a fork  // 哲学者1が右フォークを取った
402	2 has taken a fork  // 哲学者2が左フォークを取った
402	2 is eating         // 哲学者2が食べている
402	3 is sleeping       // 哲学者3が眠っている...zzz
414	1 died              // 哲学者1が餓死した
```
`哲学者1`が餓死してシュミレーションは終了です...<br>

さて、哲学者を殺さずにシュミレーションを終了させてみましょう。

```shell
>  ./philo 3 410 200 200 1
```

前回と同様に`3`人の哲学者が食事間隔`410`ms以内、食事時間`200`ms、睡眠時間`200`msで生活します。<br>
ただし、前回と異なるのはそれぞれが`1`回食事をしたらシュミレーションは終了します。

```
1	1 has taken a fork  // 哲学者1が右フォークを取った
1	1 has taken a fork  // 哲学者1が左フォークを取った
1	1 is eating         // 哲学者1が1回目のご飯を食べている
1	3 has taken a fork  // 哲学者3が右フォークを取った
202	3 has taken a fork  // 哲学者3が左フォークを取った
202	3 is eating         // 哲学者3が1回目のご飯を食べている
202	2 has taken a fork  // 哲学者2が右フォークを取った
402	2 has taken a fork  // 哲学者2が左フォークを取った
402	2 is eating         // 哲学者2が1回目のご飯を食べている
```

哲学者1、哲学者3、哲学者2の順番で1回ずつご飯を食べてシュミレーションは終了です。<br>
誰も死なずにシュミレーションを終えることができました👏

## ✅エラーケース

エラーが起こった際には、それに応じたエラー番号とメッセージが表示されます。<br>
例えば以下ような感じです。

```
> ./philo 300000 410 200 200
ERROR 2 : `number_of_philosophers` is invalid.
```

### 1

引数の個数が不正です。<br>
引数は3〜4個にしてください。

### 2

取ることができる`number_of_philosophers`の値域がら外れています。<br>
2以上200以下で渡してください。<br>
もしくは、数字以外を入力しないでください。

### 3

`time_to_die`・`time_to_eat`・`time_to_sleep`の値域から外れています。<br>
0以上で指定してください。<br>
数字以外が含まれていた場合には0として扱います。

### 4

`number_of_times_each_philosopher_must_eat`の値域から外れています。<br>
0より大きい値を指定してください。<br>
数字以外が含まれていた場合には0として扱います。

### 10

`mutex`を初期化する際のエラーが発見されました。

### 11

スレッドを作成する際にエラーが発見されました。
