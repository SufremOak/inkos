from fastapi import FastAPI
from fastapi.responses import FileResponse
from fastapi.staticfiles import StaticFiles

app = FastAPI()

# Mount both folders as static
app.mount("/public", StaticFiles(directory="public"), name="public")
app.mount("/src", StaticFiles(directory="src"), name="src")

# Default route to index.html
@app.get("/")
async def root():
    return FileResponse("public/index.html")
