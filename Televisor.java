public class Televisor {
    // Defina uma classe Televisor com os atributos: canal, volume e ligado. Inclua
    // na classe um construtor,
    private int canal;
    private int volume;
    private boolean ligado;

    public Televisor() {
        this.canal = 1;
        this.volume = 8;
        this.ligado = false;
    }

    public void ligar() {
        this.ligado = true;
    }

    public void desligar() {
        this.ligado = false;
    }

    public void aumentarVolume() {
        this.volume++;
    }

    public void diminuirVolume() {
        this.volume--;
    }

    public void trocarCanal(int canal) {
        this.canal = canal;
    }

    public String toString() {
        return "canal: " + canal + "\nvolume: " + volume + "\nligado: " + ligado;
    }

}