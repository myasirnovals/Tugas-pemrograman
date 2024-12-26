import java.util.Random;

class RamalanBuruk extends Ramalan {
    private String[] ramalanBuruk = {
            "Hari ini mungkin terlihat tenang, tetapi waspadalah terhadap rintangan di masa depan. Tetaplah rendah hati dan bersiap untuk menghadapinya dengan bijak. (sue-kyō)",
            "Kondisi akan menjadi sulit, namun tidak sepenuhnya buruk. Dengan usaha dan kehati-hatian, kamu dapat mengurangi dampaknya. (han-kyō)",
            "Kesulitan kecil mungkin menghalangi jalanmu hari ini. Jangan menyerah, karena solusi selalu ada jika kamu tetap tenang. (shō-kyō)",
            "Hari ini mungkin penuh tantangan, namun tetaplah waspada dan jangan bertindak gegabah. Segala kesulitan dapat diatasi dengan kesabaran. (kyō)",
            "Vanitas vanitatum et omnia vanitas (dai-kyō)"
    };

    @Override
    String getRamalan() {
        Random random = new Random();
        return ramalanBuruk[random.nextInt(ramalanBuruk.length)];
    }
}