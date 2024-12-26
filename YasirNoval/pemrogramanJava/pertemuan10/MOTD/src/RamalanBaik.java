import java.util.Random;

class RamalanBaik extends Ramalan {
    private String[] ramalanBaik = {
            "Hari ini, keberuntungan besar berpihak padamu. Semua rencanamu akan berjalan dengan lancar, jadi manfaatkan setiap peluang dengan penuh percaya diri. (dai-kichi)",
            "Keberuntungan menyertai langkahmu, meski tak selalu sempurna. Tetaplah berusaha dan nikmati hasil yang cukup baik (chū-kichi)",
            "Hal-hal kecil akan membawa kebahagiaan hari ini. Hargai setiap momen kecil yang penuh arti. (shō-kichi)",
            "Hari ini akan berjalan normal, tapi tetap ada peluang untuk menemukan kebahagiaan sederhana jika kamu mencarinya. (kichi)",
            "Beberapa hal mungkin berjalan sesuai harapan, sementara yang lain butuh usaha ekstra. Tetaplah seimbang dan sabar. (han-kichi)",
            "Meskipun hari ini tidak luar biasa, keberuntungan besar menantimu di masa depan. Bersiaplah untuk saat itu. (sue-kichi)",
            "Keberuntungan kecil akan menghampirimu dalam waktu dekat. Jangan buru-buru, nikmati proses menuju keberhasilan. (sue-shō-kichi)"
    };

    @Override
    String getRamalan() {
        Random random = new Random();
        return ramalanBaik[random.nextInt(ramalanBaik.length)];
    }
}