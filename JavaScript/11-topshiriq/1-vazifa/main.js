// body
Object.assign(document.body.style,{
    backgroundColor: "yellow",
    margin: "0px",
    padding: "0px"
})

// H1
const h1 = Object.assign(document.createElement("h1"),{
    textContent: "CSS COLOR TEXT BOX",
    className: "main_text"
})
Object.assign(h1.style, {
    color: "red",
    fontSize: "90px",
    textAlign: "center"
})

document.body.appendChild(h1)

// Main div
const main_div = Object.assign(document.createElement("div"), {
    className: "main_div",
})

Object.assign(main_div.style, {
    display: "grid",
    gridTemplateColumns: "repeat(2, 1fr)",
    gridTemplateRows: "repeat(2, 1fr)",
    gap: "10px",
    justifyItems: "center",
    alignItems: "center",
    padding: "40px"
})

let content = ["div1", "div2", "div3", "div4"]

for (let i in content) {
    main_div.appendChild(
        Object.assign(document.createElement("div"), {
            textContent: "Lorem ipsum dolor, sit amet consectetur adipisicing elit. Sit, quidem.",
            className: content[i],
        })
    ) 
}

document.body.appendChild(main_div)

let div_color = ["lightblue", "grey", "pink", "red"]
let all_divs = document.querySelectorAll(".main_div > div")

for (let i = 0; i < all_divs.length; i++) {
    console.log(i)
    Object.assign(all_divs[i].style, {
        padding: "40px",
        backgroundColor: div_color[i],
        borderRadius: "5px"
    })
    
}

//Footer
const footer_div = Object.assign(document.createElement("div"), {
    className: "footer_div",
}) 
Object.assign(footer_div.style, {
    display: "flex",
    gap: "10px",
    flexDirection: "column",
    color: "white",
    margin: "0 10px"
})

let foter1 = Object.assign(document.createElement("div"), {
    className: "footer1",
    textContent: "Lorem ipsum dolor, sit amet consectetur adipisicing elit. Sit, quidem."
})
Object.assign(foter1.style, {
    padding: "40px",
    backgroundColor: "green",
})

let foter2 = Object.assign(document.createElement("div"), {
    className: "footer2",
    textContent: "Lorem ipsum dolor, sit amet consectetur adipisicing elit. Sit, quidem."
})
Object.assign(foter2.style, {
    padding: "40px",
    backgroundColor: "purple",
})

footer_div.appendChild(foter1)
footer_div.appendChild(foter2)
document.body.appendChild(footer_div)