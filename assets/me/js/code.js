function doHide(obj){
  if(obj.nextSibling.style.display=='block') 
    obj.nextSibling.style.display='none';
  else	
    obj.nextSibling.style.display='block';
}

function doShow(obj){
  if(obj.innerText=='[+]'){
    obj.nextSibling.style.display='block';
    obj.innerText = '[-]';
  }else{
    obj.nextSibling.style.display='none';
    obj.innerText = '[+]';
  }
}
