import java.util.Random;

public class App {

    private static void quicksort(int[] array, int esq, int dir) {
			
        int part;
        if (esq < dir){
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


    private static void randomFillArray(int[] array){

        Random randomComSeed = new Random(1);

        for (int i = 0; i < array.length; i++){
            array[i] = randomComSeed.nextInt(10);
        } 
    }

    private static void fillArray(int[] array){
        
        for (int i = 0; i < array.length; i++){
            array[i] = i+1;
        }       
    }
    public static void main(String[] args) throws Exception {

        int[] vetor = new int[10000];
        int[] vetor2 = new int[10000];

        long[] tempos = new long[10];
        long[] temposOrdenados = new long[10];


        long inicio = 0;
        long fim = 0;

        for (int i = 0; i < 10; i++){
            randomFillArray(vetor);
            inicio = System.currentTimeMillis();
            quicksort(vetor, 0, vetor.length - 1);
            fim = System.currentTimeMillis();  
            tempos[i] = fim - inicio;
        }

        for (int i = 0; i < 10; i++){
            fillArray(vetor2);
            inicio = System.currentTimeMillis();
            quicksort(vetor2, 0, vetor2.length - 1);
            fim = System.currentTimeMillis();
            temposOrdenados[i] = fim - inicio;
        }

        double media1 = 0.0;
        
        for(int i=0; i < tempos.length; i++){
            media1 += tempos[i];
        }

        System.out.println("Média dos aleatórios: " + media1/10);

        double media2 = 0.0;

        for(int i=0; i < temposOrdenados.length; i++){
            media2 += temposOrdenados[i];
        }

        System.out.println("Média dos ordenados: " + media2/10);
    }
}
