function openbox(url)
{
    var box=document.getElementById('box');
    document.getElementById('shadowing').style.display='block';

    var title=document.getElementById('boxtitle');
    title.innerHTML=url;

    var content=document.getElementById('boxcontent');
    content.style.padding="0";
    content.innerHTML="<img src=" + url + "/>";
    box.style.display='block';
}

function closebox()
{
    document.getElementById('box').style.display='none';
    document.getElementById('shadowing').style.display='none';
}