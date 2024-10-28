package Progam.V_5;

public class AlbumLagu {
    String judul;
    String artis;
    int tahunRilis;

    /**
     * Konstruktor
     * @param judul
     * @param artis
     * @param tahunRilis
     */
    public AlbumLagu(String judul, String artis, int tahunRilis) {
        this.judul = judul;
        this.artis = artis;
        this.tahunRilis = tahunRilis;
    }

    public String infoJudul() {
        return (judul);
    }

    public String infoArtis() {
        return (artis);
    }

    public int infoTahunRilis() {
        return (tahunRilis);
    }

    public static void main(String[] args) {
        AlbumLagu album = new AlbumLagu("I Love Java Code", "Rezki", 2021);
        System.out.println("Judul Album: " + album.infoJudul());
        System.out.println("Artis: " + album.infoArtis());
        System.out.println("Tahun: " + album.infoTahunRilis());
    }
}
