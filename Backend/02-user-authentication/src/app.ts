import express from "express";
import type { Request, Response } from "express";
import { userRouter } from "./routes/userRouter.js";
import { errorHandler } from "./middlewares/errorHandler.js";

export const app = express();

app.use(express.json());

app.use("/user", userRouter);

app.get("/", (_req: Request, res: Response) => {
  res.status(200).json({ message: "user-authentication" });
});

app.use(errorHandler);
