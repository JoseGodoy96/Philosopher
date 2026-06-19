Philosophers


Una solución en C al clásico problema de concurrencia de los filósofos
comensales, resuelto con hilos (pthread) y mutexes.



Proyecto realizado en la escuela 42 (campus de 42 Málaga). Por tratarse de una
entrega ya evaluada y cerrada, el repositorio contiene un único commit: el
proyecto está terminado y no recibe nuevos cambios.


📖 Descripción

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


🧠 Conceptos trabajados


Creación y sincronización de hilos: pthread_create, pthread_join.
Exclusión mutua con mutexes: pthread_mutex_lock / unlock.
Prevención de deadlocks y data races.
Medición precisa de tiempos con gettimeofday y esperas controladas.



⚙️ Argumentos

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


🗂️ Estructura del proyecto

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


🚀 Compilación

bashcd philo
make            # compila el ejecutable "philo"
make clean      # elimina los archivos objeto
make fclean     # elimina objetos y ejecutable
make re         # recompila desde cero


👤 Autor

jgodoy-m — Estudiante de 42 Málaga


📝 Nota sobre el repositorio

Este proyecto forma parte del currículo de 42. Al ser una entrega ya finalizada
y corregida, el historial del repositorio se compone de un solo commit. No está
en desarrollo activo: el código está completo y cumple los requisitos de la consigna.
