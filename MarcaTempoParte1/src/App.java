import java.util.Random;

public class App {

    private static void quicksort(int[] array, int esq, int dir) {

        int part;
        if (esq < dir) {
            part = particao(array, esq, dir);
            quicksort(array, esq, part - 1);
            quicksort(array, part + 1, dir);
        }
    }

    private static int particao(int[] array, int inicio, int fim) {

        int pivot = array[fim];
        int part = inicio - 1;
        for (int i = inicio; i < fim; i++) {
            if (array[i] < pivot) {
                part++;
                swap(array, part, i);
            }
        }
        part++;
        swap(array, part, fim);
        return (part);
    }

    private static void swap(int[] array, int i, int j) {

        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    /////////////////////////////////////////////////////////////

    private static void bubblesort(int[] array) {
        for (int i = array.length - 1; i > 0; i--) {

            for (int w = 0; w < i; w++) {

                if (array[w] > array[w + 1]) {
                    int aux = array[w];
                    array[w] = array[w + 1];
                    array[w + 1] = aux;
                }
            }
        }
    }

    /////////////////////////////////////////////////////////////

    private static void randomFillArray(int[] array, int seed) {

        Random randomComSeed = new Random(seed);

        for (int i = 0; i < array.length; i++) {
            array[i] = randomComSeed.nextInt(10);
        }
    }

    /////////////////////////////////////////////////////////////

    public static void main(String[] args) throws Exception {

        int[] vetor625 = new int[62500];

        long[] temposQuick = new long[50];
        long[] temposBubble = new long[50];

        long inicio = 0;
        long fim = 0;

        for (int i = 0; i < 50; i++) {

            randomFillArray(vetor625, i);
            inicio = System.currentTimeMillis();
            quicksort(vetor625, 0, vetor625.length - 1);
            fim = System.currentTimeMillis();
            temposQuick[i] = fim - inicio;

            inicio = System.currentTimeMillis();
            bubblesort(vetor625);
            fim = System.currentTimeMillis();
            temposBubble[i] = fim - inicio;
        }

        double media2 = 0.0;
        double media1 = 0.0;

        for (int i = 0; i < temposQuick.length; i++) {
            media1 += temposQuick[i];
            media2 += temposBubble[i];

        }
        System.out.println("Média Quicksort [62500]: " + media1 / 50);
        System.out.println("Média Bubblesort [62500]: " + media2 / 50);

        /////////////////////////////////////////////////////////////
        System.out.println("-=-=-=-=-=-=-=-=-=-");
        /////////////////////////////////////////////////////////////

        int[] vetor125 = new int[125000];

        for (int i = 0; i < 50; i++) {

            randomFillArray(vetor125, i);
            inicio = System.currentTimeMillis();
            quicksort(vetor125, 0, vetor125.length - 1);
            fim = System.currentTimeMillis();
            temposQuick[i] = fim - inicio;

            inicio = System.currentTimeMillis();
            bubblesort(vetor125);
            fim = System.currentTimeMillis();
            temposBubble[i] = fim - inicio;
        }

        media2 = 0.0;
        media1 = 0.0;

        for (int i = 0; i < temposQuick.length; i++) {
            media1 += temposQuick[i];
            media2 += temposBubble[i];

        }
        System.out.println("Média Quicksort [125000]: " + media1 / 50);
        System.out.println("Média Bubblesort [125000]: " + media2 / 50);

        /////////////////////////////////////////////////////////////
        System.out.println("-=-=-=-=-=-=-=-=-=-");
        /////////////////////////////////////////////////////////////

        int[] vetor250 = new int[250000];

        for (int i = 0; i < 50; i++) {

        randomFillArray(vetor250, i);
        inicio = System.currentTimeMillis();
        quicksort(vetor250, 0, vetor250.length - 1);
        fim = System.currentTimeMillis();
        temposQuick[i] = fim - inicio;

        inicio = System.currentTimeMillis();
        bubblesort(vetor250);
        fim = System.currentTimeMillis();
        temposBubble[i] = fim - inicio;
        }

        media2 = 0.0;
        media1 = 0.0;

        for (int i = 0; i < temposQuick.length; i++) {
        media1 += temposQuick[i];
        media2 += temposBubble[i];

        }
        System.out.println("Média Quicksort [250000]: " + media1 / 50);
        System.out.println("Média Bubblesort [250000]: " + media2 / 50);

        /////////////////////////////////////////////////////////////
        System.out.println("-=-=-=-=-=-=-=-=-=-");
        /////////////////////////////////////////////////////////////

        int[] vetor325 = new int[325000];

        for (int i = 0; i < 50; i++) {

        randomFillArray(vetor325, i);
        inicio = System.currentTimeMillis();
        quicksort(vetor325, 0, vetor325.length - 1);
        fim = System.currentTimeMillis();
        temposQuick[i] = fim - inicio;

        inicio = System.currentTimeMillis();
        bubblesort(vetor325);
        fim = System.currentTimeMillis();
        temposBubble[i] = fim - inicio;
        }

        media2 = 0.0;
        media1 = 0.0;

        for (int i = 0; i < temposQuick.length; i++) {
        media1 += temposQuick[i];
        media2 += temposBubble[i];

        }
        System.out.println("Média Quicksort [325000]: " + media1 / 50);
        System.out.println("Média Bubblesort [325000]: " + media2 / 50);
    }
}
