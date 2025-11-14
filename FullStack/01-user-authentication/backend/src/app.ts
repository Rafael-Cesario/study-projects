import express, { json, type Request, type Response } from "express";
import { userRouter } from "./routes/userRouter";

const app = express();

app.use(json());

app.get("/", (_req: Request, res: Response) => {
  res.json({ message: "User authentication" });
});

app.use("/user", userRouter);

export { app };
