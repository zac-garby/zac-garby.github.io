var pre

function load() {
    let queryParams = new URLSearchParams(window.location.search)
    pre = document.getElementById("output")
    let url = queryParams.get("url")
    let selector = queryParams.get("selector") || "code"

    if (url == null) {
        pre.innerHTML = "no URL specified."
        pre.className = "error"
    } else {
        var oReq = new XMLHttpRequest()
        oReq.addEventListener("load", loadPage)
        oReq.open("GET", url)
        oReq.send()
    }
}

function loadPage() {
    pre.innerHTML = this.responseText
}