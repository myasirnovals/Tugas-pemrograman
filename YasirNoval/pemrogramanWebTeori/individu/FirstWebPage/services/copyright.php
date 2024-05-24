<?php
function copryright($name1, $name2)
{
    $code1 = base64_encode($name1);
    $code2 = base64_encode($name2);

    $codey = "eWFzaXI=";
    $codea = "YXJ5YQ==";

    if ($code1 == $codey and $code2 == $codea) {
        return true;
    } else {
        return false;
    }
}
