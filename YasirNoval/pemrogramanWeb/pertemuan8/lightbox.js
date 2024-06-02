function openbox(url)
{
    let box=document.getElementById('box');
    document.getElementById('shadowing').style.display='block';

    let title=document.getElementById('boxtitle');
    title.innerHTML=url;

    let content=document.getElementById('boxcontent');
    content.style.padding="0";
    content.innerHTML= `<img src=${url} alt=${url} width="100%" height="100%">`;
    box.style.display='block';
}

function closebox()
{
    document.getElementById('box').style.display='none';
    document.getElementById('shadowing').style.display='none';
}