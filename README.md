# Philosophers
 
> A C solution to the classic **dining philosophers** concurrency problem, solved
> with **threads (`pthread`) and mutexes**.
 
Project completed at the **42** school (42 Málaga campus). Since it is an already
evaluated and closed submission, the repository contains **a single commit**: the
project is **finished** and receives no further changes.
 
---
 
## 📖 Description
 
**Philosophers** is 42's introductory project to **concurrent programming**. It
poses the well-known dining philosophers problem:
 
> Several philosophers are sitting around a round table. Between each pair of
> philosophers there is **a single fork**. Each philosopher alternates between
> **thinking**, **eating**, and **sleeping**, but to eat they need to pick up the
> **two forks** next to them. The challenge is to organize access to the forks so
> that no philosopher starves (avoiding **deadlocks** and **race conditions**), and
> to detect when one of them dies of starvation.
 
In this implementation:
 
- **Each philosopher is a thread** (`pthread`).
- **Each fork is a mutex**, so only one philosopher can hold it at a time.
- Additional mutexes protect **message printing**, the **death state**, and each
  philosopher's **last meal**, preventing threads from accessing the same data
  simultaneously.
- A **monitor** continuously watches the state of the table to detect when a
  philosopher has gone too long without eating and must die, or when all of them
  have eaten the required number of times.
The special case of **a single philosopher** is handled: they pick up their only
fork, cannot eat, and die once their time runs out.
 
---
 
## 🧠 Concepts covered
 
- Thread creation and synchronization: `pthread_create`, `pthread_join`.
- Mutual exclusion with mutexes: `pthread_mutex_lock` / `unlock`.
- Prevention of **deadlocks** and **data races**.
- Precise time measurement with `gettimeofday` and controlled waits.
---
 
## ⚙️ Arguments
 
```bash
./philo n_philos t_die t_eat t_sleep [times_must_eat]
```
 
| Argument          | Meaning                                                             |
| ----------------- | ------------------------------------------------------------------- |
| `n_philos`        | Number of philosophers (and forks).                                 |
| `t_die` (ms)      | Time without eating after which a philosopher dies.                 |
| `t_eat` (ms)      | Time a philosopher takes to eat.                                    |
| `t_sleep` (ms)    | Time spent sleeping.                                                |
| `times_must_eat`  | *(optional)* If every philosopher eats this many times, the simulation ends. |
 
### Examples
 
```bash
./philo 5 800 200 200        # 5 philosophers, no meal limit
./philo 5 800 200 200 7      # ends when all have eaten 7 times
./philo 1 800 200 200        # single-philosopher case (must die)
```
 
### Output
 
Each state change is printed with its timestamp:
 
```
<timestamp_ms> <philo_id> has taken a fork
<timestamp_ms> <philo_id> is eating
<timestamp_ms> <philo_id> is sleeping
<timestamp_ms> <philo_id> is thinking
<timestamp_ms> <philo_id> died
```
 
---
 
## 🗂️ Project structure
 
```
Philosopher/
└── philo/
    ├── Makefile
    ├── include/
    │   └── philosophers.h
    └── src/
        ├── philosophers.c   # main, each thread's routine, and thread creation
        ├── init.c           # initialization of the table and the philosophers
        ├── parsing.c        # argument validation
        ├── routine.c        # actions: think, eat, sleep, take/drop forks
        ├── monitor.c        # death watching and end of the simulation
        └── utils.c          # timing, protected messages, and memory freeing
```
 
---
 
## 🚀 Compilation
 
```bash
cd philo
make            # builds the "philo" executable
make clean      # removes the object files
make fclean     # removes objects and executable
make re         # recompiles from scratch
```
 
---
 
## 👤 Author
 
**jgodoy-m** — Student at [42 Málaga](https://www.42malaga.com/)
 
---
 
## 📝 Note about this repository
 
This project is part of the **42** curriculum. As it is an already finished and
graded submission, the repository's history consists of **a single commit**. It is
not under active development: the code is complete and meets the requirements of the
assignment.
 

# Philosophers


Una solución en C al clásico problema de concurrencia de los filósofos
comensales, resuelto con hilos (pthread) y mutexes.



Proyecto realizado en la escuela 42 (campus de 42 Málaga). Por tratarse de una
entrega ya evaluada y cerrada, el repositorio contiene un único commit: el
proyecto está terminado y no recibe nuevos cambios.


# 📖 Descripción

Philosophers es el proyecto de introducción a la programación concurrente
en 42. Plantea el conocido problema de los filósofos comensales:


Varios filósofos están sentados alrededor de una mesa redonda. Entre cada par de
filósofos hay un solo tenedor. Cada filósofo alterna entre pensar,
comer y dormir, pero para comer necesita coger los dos tenedores que
tiene a su lado. El reto es organizar el acceso a los tenedores para que ningún
filósofo se quede sin comer (evitando deadlocks y condiciones de carrera),
y detectar si alguno muere de hambre.



En esta implementación:


Cada filósofo es un hilo (pthread).
Cada tenedor es un mutex, de modo que solo un filósofo puede sostenerlo a la
vez.
Mutexes adicionales protegen la impresión de mensajes, el estado de muerte
y la última comida de cada filósofo, evitando que los hilos accedan a los
mismos datos simultáneamente.
Un monitor vigila continuamente el estado de la mesa para detectar cuándo un
filósofo lleva demasiado tiempo sin comer y debe morir, o cuándo todos han comido
el número de veces requerido.


El caso especial de un solo filósofo está contemplado: coge su único tenedor, no
puede comer y muere cuando se agota su tiempo.


# 🧠 Conceptos trabajados


Creación y sincronización de hilos: pthread_create, pthread_join.
Exclusión mutua con mutexes: pthread_mutex_lock / unlock.
Prevención de deadlocks y data races.
Medición precisa de tiempos con gettimeofday y esperas controladas.



# ⚙️ Argumentos

bash./philo n_filosofos t_morir t_comer t_dormir [veces_que_debe_comer]

ArgumentoSignificadon_filosofosNúmero de filósofos (y de tenedores).t_morir (ms)Tiempo sin comer tras el cual un filósofo muere.t_comer (ms)Tiempo que tarda un filósofo en comer.t_dormir (ms)Tiempo que pasa durmiendo.veces_que_debe_comer(opcional) Si todos comen este número de veces, la simulación termina.

Ejemplos

bash./philo 5 800 200 200        # 5 filósofos, sin límite de comidas
./philo 5 800 200 200 7      # termina cuando todos hayan comido 7 veces
./philo 1 800 200 200        # caso de un solo filósofo (debe morir)

Salida

Cada cambio de estado se imprime con su marca de tiempo:

<timestamp_ms> <id_filosofo> has taken a fork
<timestamp_ms> <id_filosofo> is eating
<timestamp_ms> <id_filosofo> is sleeping
<timestamp_ms> <id_filosofo> is thinking
<timestamp_ms> <id_filosofo> died


# 🗂️ Estructura del proyecto

Philosopher/
└── philo/
    ├── Makefile
    ├── include/
    │   └── philosophers.h
    └── src/
        ├── philosophers.c   # main, rutina de cada hilo y creación de hilos
        ├── init.c           # inicialización de la mesa y los filósofos
        ├── parsing.c        # validación de argumentos
        ├── routine.c        # acciones: pensar, comer, dormir, coger/soltar tenedores
        ├── monitor.c        # vigilancia de muertes y fin de la simulación
        └── utils.c          # tiempos, mensajes protegidos y liberación de memoria


# 🚀 Compilación

bashcd philo
make            # compila el ejecutable "philo"
make clean      # elimina los archivos objeto
make fclean     # elimina objetos y ejecutable
make re         # recompila desde cero


# 👤 Autor

jgodoy-m — Estudiante de 42 Málaga


# 📝 Nota sobre el repositorio

Este proyecto forma parte del currículo de 42. Al ser una entrega ya finalizada
y corregida, el historial del repositorio se compone de un solo commit. No está
en desarrollo activo: el código está completo y cumple los requisitos de la consigna.
